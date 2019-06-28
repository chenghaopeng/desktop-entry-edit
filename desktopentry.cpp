#include "desktopentry.h"

namespace DesktopEntryItem {

    int getTypeByKey(QString key) {
        if (key == KEY_NAME || key == KEY_EXEC || key == KEY_TYPE || key == KEY_ICON || key == KEY_GENERICNAME || key == KEY_COMMENT || key == KEY_VERSION) return 1;
        if (key == KEY_TERMINAL) return 2;
        if (key == KEY_CATEGORIES) return 3;
        return 0;
    }

    //Item
    bool Item::itemKeyIs(QString key) {
        return this->key == key;
    }
    QString Item::toString() {
        return this->key + "=" + this->value;
    }
    QString Item::getKey() {
        return this->key;
    }
    QString Item::getValue() {
        return this->value;
    }

    //TextItem
    TextItem::TextItem(QString key, QString value) {
        this->key = key;
        this->value = value;
    }

    //BooleanItem
    BooleanItem::BooleanItem(QString key, QString value) {
        this->key = key;
        this->value = value.toLower();
        this->bvalue = this->value == "true";
    }
    BooleanItem::BooleanItem(QString key, bool value) {
        this->key = key;
        this->bvalue = value;
        this->value = value? "true": "false";
    }
    bool BooleanItem::getBooleanValue() {
        return this->bvalue;
    }

    //ListItem
    ListItem::ListItem(QString key, QString value) {
        this->key = key;
        this->list.clear();
        this->list.append(value.split(";"));
        this->value = value;
    }
    ListItem::ListItem(QString key, QList<QString> value) {
        this->key = key;
        this->list.clear();
        this->list.append(value);
        this->value = list.join(";");
    }
    QList<QString>* ListItem::getListValue() {
        return new QList<QString>(this->list);
    }

}

DesktopEntry::DesktopEntry() {
    this->items.clear();
}
DesktopEntryItem::Item* DesktopEntry::getItemByKey(QString key) {
    for (int i=0; i<this->items.size(); ++i) {
        if (this->items[i]->itemKeyIs(key)) {
            return this->items[i];
        }
    }
    return nullptr;
}
QString DesktopEntry::getValue(QString key) {
    DesktopEntryItem::Item* item = DesktopEntry::getItemByKey(key);
    return item->getValue();
}
bool DesktopEntry::getBooleanValue(QString key) {
    DesktopEntryItem::BooleanItem* item = static_cast<DesktopEntryItem::BooleanItem*>(DesktopEntry::getItemByKey(key));
    return item->getBooleanValue();
}
QList<QString>* DesktopEntry::getListValue(QString key) {
    DesktopEntryItem::ListItem* item = static_cast<DesktopEntryItem::ListItem*>(DesktopEntry::getItemByKey(key));
    return item->getListValue();
}
void DesktopEntry::append(DesktopEntryItem::Item *item) {
    this->items.append(item);
}

namespace DesktopEntryIO {
    bool saveToFile(DesktopEntry* desktopEntry, QString fileName) {
        QString str = DESKTOP_ENTRY;
        foreach(DesktopEntryItem::Item* item, desktopEntry->items) {
            str += "\n" + item->toString();
        }
        QByteArray byteArray = str.toUtf8();
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return false;
        qint64 res = file.write(byteArray, byteArray.length());
        file.close();
        return res != -1;
    }
    bool readFromFile(DesktopEntry* desktopEntry, QString fileName) {
        QFile file(fileName);
        try {
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                throw;
            QTextStream in(&file);
            in.setAutoDetectUnicode(true);
            QString str = in.readLine();
            if (str.simplified().toLower() != DESKTOP_ENTRY) {
                throw;
            }
            while (!in.atEnd()) {
                str = in.readLine().trimmed();
                int pos = str.indexOf("=");
                if (pos < 0) throw;
                QString key = str.left(pos + 1), value = str.right(str.size() - pos - 1);
                if (key.contains("[")) throw;
                int typeOfKey = DesktopEntryItem::getTypeByKey(key);
                if (typeOfKey == 0) throw;
                DesktopEntryItem::Item* item;
                if (typeOfKey == 1) item = new DesktopEntryItem::TextItem(key, value);
                if (typeOfKey == 2) item = new DesktopEntryItem::BooleanItem(key, value);
                if (typeOfKey == 3) item = new DesktopEntryItem::ListItem(key, value);
                desktopEntry->items.append(item);
            }
            file.close();
            return true;
        }
        catch(...) {
            file.close();
            return false;
        }
    }
}
