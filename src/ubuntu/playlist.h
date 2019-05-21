#include <cplugin.h>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <cordova.h>
#include "AudioTrack.h"

#include <QJSValue>

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

/**
 * Clear the entire playlist. This will result in the STOPPED event being raised.
 */
void clearAllItems(int, int);

/**
 * Sets the entire list of tracks to be played by the playlist.
 * This will clear all previous items from the playlist.
 * If you pass options.retainPosition = true, the current playback position will be
 * recorded and used when playback restarts. This can be used, for example, to set the
 * playlist to a new set of tracks, but retain the currently-playing item to avoid skipping.
 */
void setPlaylistItems(int scId, int ecId, const QJSValue &);

/**
 * Add a single track to the end of the playlist
 */
void addItem(int scId, int ecId, const QJSValue &);

/**
 * Adds the list of tracks to the end of the playlist.
 */
void addAllItems(int scId, int ecId, const QJSValue &);

/**
 * Begin playback. If no tracks have been added, this has no effect.
 */
void play(int scId, int ecId);

/**
 * Pause playback
 */
void pause(int scId, int ecId);
//void playTrackByIndex(int scId, int ecId, QString &id, int index);

/**
 * Seek to the given position in the currently playing track. If the value exceeds the track length,
 * the track will complete and playback of the next track will begin.
 */
void seekTo(int scId, int ecId, qint64);

/**
 * Reports the playback position of the current item. You are recommended to handle the onStatus events
 * rather than this value, as this value will be stale by the time you receive it.
 */
void getPlaybackPosition(int scId, int ecId);

private slots:

int addItem(int scId, int ecId, const AudioTrack &);
int setPlaylistItems(int scId, int ecId, const AudioTrackList);
int addAllItems(int scId, int ecId, const AudioTrackList);

private:
	QMediaPlaylist m_playlist;
	QMediaPlayer m_player;
};

#define Playlist RmxAudioPlayer
