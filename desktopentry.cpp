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
    QList<QString> ListItem::getListValue() {
        return this->list;
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
QList<QString> DesktopEntry::getListValue(QString key) {
    DesktopEntryItem::ListItem* item = static_cast<DesktopEntryItem::ListItem*>(DesktopEntry::getItemByKey(key));
    return item->getListValue();
}
