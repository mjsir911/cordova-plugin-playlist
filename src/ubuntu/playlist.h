#include <cplugin.h>
#include <cordova.h>

//class RmxAudioPlayerItem;

//typedef QMap<QString, QVariant> AudioTrack;

class RmxAudioPlayer: public CPlugin {
	Q_OBJECT

public:
	explicit RmxAudioPlayer(Cordova *);

	virtual const QString fullName() override {
		return "RmxAudioPlayer";
	}

	virtual const QString shortName() override {
		return "RmxAudioPlayer";
	}

public slots:
	//void create(int scId, int ecId, const QString &id);

// translation functions
//void getPosition(int scId, int ecId, const QString &id);
//void on(int scId, int ecId, const QString &id, QString &eventName, int OnStatusCallbackId);
//void setPlaylistItems(int scId, int ecId, const QString &id, AudioTrack items);
void play(int scId, int ecId);
//void playTrackByIndex(int scId, int ecId, QString &id, int index);

private:
	//QMap<QString, QSharedPointer<RmxAudioPlayerItem>> objectsDict;
};

/*
class RmxAudioPlayerItem: public QObject {
	Q_OBJECT
public:
	RmxAudioPlayerItem(const QString &id, RmxAudioPlayer *plugin);
};
*/
