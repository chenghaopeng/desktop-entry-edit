#include "desktopentry.h"

namespace DesktopEntryItem {

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
    void Item::setValue(QString value) {
        this->value = value;
    }

    //TextItem
    TextItem::TextItem(QString key, QString value) {
        this->key = key;
        this->value = value;
        this->tag = "";
    }
    TextItem::TextItem(QString key, QString value, QString tag) {
        this->key = key;
        this->value = value;
        this->tag = tag;
    }
    QString TextItem::getTag() {
        return this->tag;
    }
    void TextItem::setTag(QString tag) {
        this->tag = tag;
    }
    bool TextItem::itemKeyIs(QString key, QString tag) {
        return this->key == key && this->tag == tag;
    }
    QString TextItem::toString() {
        if (tag.size() == 0) {
            return this->key + "=" + this->value;
        }
        else {
            return this->key + "[" + this->tag + "]=" + this->value;
        }
    }

    //BooleanItem
    BooleanItem::BooleanItem(QString key, QString value) {
        this->key = key;
        this->setValue(value);
    }
    BooleanItem::BooleanItem(QString key, bool value) {
        this->key = key;
        this->setValue(value);
    }
    void BooleanItem::setValue(QString value) {
        this->value = value.toLower();
        this->bvalue = this->value == "true";
    }
    void BooleanItem::setValue(bool value) {
        this->bvalue = value;
        this->value = value? "true": "false";
    }
    bool BooleanItem::getBooleanValue() {
        return this->bvalue;
    }

    //ListItem
    ListItem::ListItem(QString key, QString value) {
        this->key = key;
        this->setValue(value);
    }
    ListItem::ListItem(QString key, QList<QString> value) {
        this->key = key;
        this->setValue(value);
    }
    void ListItem::setValue(QString value) {
        this->list.clear();
        this->list.append(value.split(";"));
        this->value = value;
    }
    void ListItem::setValue(QList<QString> value) {
        this->list.clear();
        this->list.append(value);
        this->value = list.join(";");
    }
    QList<QString> ListItem::getListValue() {
        return this->list;
    }

}

DesktopEntry::DesktopEntry() {
    this->items.clear();
}
int DesktopEntry::getIndexByKey(QString key) {
    for (int i=0; i<this->items.size(); ++i) {
        if (this->items[i].itemKeyIs(key)) {
            return i;
        }
    }
    return -1;
}
int DesktopEntry::getIndexByKeyTag(QString key, QString tag) {
    for (int i=0; i<this->items.size(); ++i) {
        if (this->items[i].itemKeyIs(key, tag)) {
            return i;
        }
    }
    return -1;
}
QString DesktopEntry::getValue(QString key) {
    int i = this->getIndex(key);
    return this->items[i].getValue();
}
QString DesktopEntry::getValue(QString key, QString tag) {

}
bool DesktopEntry::getBooleanValue(QString key) {

}
QList<QString> DesktopEntry::getListValue(QString key) {

}
int DesktopEntry::readFromFile(QString fileName) {

}
int DesktopEntry::writeToFile(QString fileName) {

}
