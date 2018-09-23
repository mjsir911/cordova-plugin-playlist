#include <cplugin.h>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <cordova.h>
#include "AudioTrack.h"

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

/**
 * Seek to the given position in the currently playing track. If the value exceeds the track length,
 * the track will complete and playback of the next track will begin.
 */
void seekTo(int scId, int ecId, int position);

/**
 * Sets the entire list of tracks to be played by the playlist.
 * This will clear all previous items from the playlist.
 * If you pass options.retainPosition = true, the current playback position will be
 * recorded and used when playback restarts. This can be used, for example, to set the
 * playlist to a new set of tracks, but retain the currently-playing item to avoid skipping.
 */
void setPlaylistItems(int scId, int ecId, const QList<QVariantMap> &);

/**
 * Add a single track to the end of the playlist
 */
void addItem(int scId, int ecId, const QVariantMap &item);

/**
 * Begin playback. If no tracks have been added, this has no effect.
 */
void play(int scId, int ecId);

/**
 * Pause playback
 */
void pause(int scId, int ecId);
//void playTrackByIndex(int scId, int ecId, QString &id, int index);

private:
	QMediaPlaylist m_playlist;
	QMediaPlayer m_player;
};

#define Playlist RmxAudioPlayer
