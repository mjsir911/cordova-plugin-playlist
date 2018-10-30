#include "playlist.h"
#include <cordova.h>
#include "AudioTrack.h"

RmxAudioPlayer::RmxAudioPlayer(Cordova *cordova): CPlugin(cordova) {
	m_cordova->execJS("console.log('hi')");
	m_player.setPlaylist(&m_playlist);
}

void RmxAudioPlayer::clearAllItems(int scId, int ecId) {
	if (!m_playlist.clear()) {
		this->cb(ecId, m_playlist.errorString());
		return;
	}
}

void RmxAudioPlayer::play(int scId, int ecd) {
	m_player.play();
}

void RmxAudioPlayer::pause(int scId, int ecId) {
	m_player.pause();
}

void RmxAudioPlayer::seekTo(int scId, int ecId, qint64 position) {
	m_player.setPosition(position);
}

int RmxAudioPlayer::setPlaylistItems(int scId, int ecId, const QJSValue &items_tmp) {
	if (!m_playlist.clear()) {
		this->cb(ecId, m_playlist.errorString());
		return -1;
	}

	for (const AudioTrack &item : items_tmp.toVariant().toList()) {
		if (!this->addItem(scId, ecId, item)) {
			return -1
		}
	}
}

int RmxAudioPlayer::addItem(int scId, int ecId, const AudioTrack &track) {
	if (!m_playlist.addMedia(track.assetUrl)) {
		this->cb(ecId, m_playlist.errorString());
		return -1
	}

	this->cb(scId, track.assetUrl);
}
