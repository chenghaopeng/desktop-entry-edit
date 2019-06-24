#ifndef DESKTOPENTRY_H
#define DESKTOPENTRY_H

#include <QString>
#include <QList>

namespace DesktopEntryItem {
    static const QString KEY_NAME = "Name", KEY_EXEC = "Exec", KEY_TYPE = "Type";
    static const QString KEY_TERMINAL = "Terminal", KEY_ICON = "Icon", KEY_GENERICNAME = "GenericName";
    static const QString KEY_COMMENT = "Comment", KEY_VERSION = "Version", KEY_CATEGORIES = "Categories";

    class Item {
    protected:
        QString key, value;
    public:
        bool itemKeyIs(QString key);
        QString toString();
        QString getKey();
        QString getValue();
        void setValue(QString value);
    };

    class TextItem: public Item {
    private:
        QString tag;
    public:
        TextItem(QString key, QString value);
        TextItem(QString key, QString value, QString tag);
        QString getTag();
        void setTag(QString tag);
        bool itemKeyIs(QString key, QString tag);
        QString toString();
    };

    class BooleanItem: public Item {
    private:
        bool bvalue;
    public:
        BooleanItem(QString key, QString value);
        BooleanItem(QString key, bool value);
        void setValue(QString value);
        void setValue(bool value);
        bool getBooleanValue();
    };

    class ListItem: public Item {
    private:
        QList<QString> list;
    public:
        ListItem(QString key, QString value);
        ListItem(QString key, QList<QString> value);
        void setValue(QString value);
        void setValue(QList<QString> value);
        QList<QString> getListValue();
    };
}

class DesktopEntry {
private:
    QList<DesktopEntryItem::Item> items;
    DesktopEntryItem::Item* getItemByKey(QString key);
public:
    DesktopEntry();
    int getIndexByKey(QString key);
    int getIndexByKeyTag(QString key, QString tag);
    /*void setValue(QString key, QString value);
    void setValue(QString key, bool value);
    void setValue(QString key, QList<QString> value);*/
    QString getValue(QString key);
    QString getValue(QString key, QString tag);
    bool getBooleanValue(QString key);
    QList<QString> getListValue(QString key);
    int readFromFile(QString fileName);
    int writeToFile(QString fileName);
};

#endif // DESKTOPENTRY_H
