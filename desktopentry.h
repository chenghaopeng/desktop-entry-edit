#ifndef DESKTOPENTRY_H
#define DESKTOPENTRY_H

#include <QString>
#include <QList>
#include <QTextStream>

namespace DesktopEntryItem {
    static const QString KEY_NAME = "Name", KEY_EXEC = "Exec", KEY_TYPE = "Type";
    static const QString KEY_TERMINAL = "Terminal", KEY_ICON = "Icon", KEY_GENERICNAME = "GenericName";
    static const QString KEY_COMMENT = "Comment", KEY_VERSION = "Version", KEY_CATEGORIES = "Categories";

    int getTypeByKey(QString key);

    class Item {
    protected:
        QString key, value;
    public:
        bool itemKeyIs(QString key);
        QString toString();
        QString getKey();
        QString getValue();
    };

    class TextItem: public Item {
//    Item with tag will be implied in second version, maybe. XD
//    private:
//        QString tag;
    public:
        TextItem(QString key, QString value);
    };

    class BooleanItem: public Item {
    private:
        bool bvalue;
    public:
        BooleanItem(QString key, QString value);
        BooleanItem(QString key, bool value);
        bool getBooleanValue();
    };

    class ListItem: public Item {
    private:
        QList<QString> list;
    public:
        ListItem(QString key, QString value);
        ListItem(QString key, QList<QString> value);
        QList<QString>* getListValue();
    };
}

class DesktopEntry {
private:
    DesktopEntryItem::Item* getItemByKey(QString key);
public:
    QList<DesktopEntryItem::Item*> items;
    DesktopEntry();
    QString getValue(QString key);
    bool getBooleanValue(QString key);
    QList<QString>* getListValue(QString key);
    void append(DesktopEntryItem::Item* item);
};

namespace DesktopEntryIO {
    const static QString DESKTOP_ENTRY = "[Desktop Entry]";
    bool saveToFile(DesktopEntry* desktopEntry, QString fileName);
    bool readFromFile(DesktopEntry* desktopEntry, QString fileName);
};

#endif // DESKTOPENTRY_H
