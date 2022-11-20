#pragma once

#include <QList>
#include <QMetaType>
#include <QString>
#include <QVector>

namespace CurseForge {

struct ModpackAuthor {
    QString name;
    QString url;
};

struct IndexedVersion {
    int addonId;
    int fileId;
    QString version;
    QString mcVersion;
    QString downloadUrl;
};

struct IndexedPack
{
    int addonId;
    QString name;
    QString description;
    QList<ModpackAuthor> authors;

    QString logoName;
    QString logoUrl;

    QString websiteUrl;
    QString issuesUrl;
    QString sourceUrl;
    QString wikiUrl;

    bool versionsLoaded = false;
    QVector<IndexedVersion> versions;
};

void loadIndexedPack(IndexedPack & m, QJsonObject & obj);
void loadIndexedPackVersions(IndexedPack & m, QJsonArray & arr);
}

Q_DECLARE_METATYPE(CurseForge::IndexedPack)
