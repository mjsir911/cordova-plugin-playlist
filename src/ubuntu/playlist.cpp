#include "playlist.h"
#include <cordova.h>
#include "AudioTrack.h"

RmxAudioPlayer::RmxAudioPlayer(Cordova *cordova): CPlugin(cordova) {
	m_cordova->execJS("console.log('hi')");
	m_player.setPlaylist(&m_playlist);
}

//void RmxAudioPlayer::create(int scId, int ecId, const QString &id) {
	//objectsDict[id] = QSharedPointer<RmxAudioPlayerItem>(new RmxAudioPlayerItem(id, this));
//}

void RmxAudioPlayer::play(int scId, int ecd) {
	m_player.play();
}

void RmxAudioPlayer::pause(int scId, int ecId) {
	m_player.pause();
}

void RmxAudioPlayer::seekTo(int scId, int ecId, int position) {
	this->cb(scId, "seekTo" + position);
}

void RmxAudioPlayer::setPlaylistItems(int scId, int ecId, const QList<QVariantMap> &items_tmp) {
	if (!m_playlist.clear()) {
		this->cb(ecId, m_playlist.errorString());
		return;
	}
	for (const AudioTrack &item : items_tmp) {
		if (!m_playlist.addMedia(item.assetUrl)) {
			this->cb(ecId, m_playlist.errorString());
			return;
		}
	}
	this->cb(scId, "hi");
}

void RmxAudioPlayer::addItem(int scId, int ecId, const QVariantMap &item_tmp) {
	AudioTrack item = item_tmp;
	if (!m_playlist.addMedia(item.assetUrl)) {
		this->cb(ecId, m_playlist.errorString());
		return;
	}
}
