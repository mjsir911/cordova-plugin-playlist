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

void RmxAudioPlayer::setPlaylistItems(int scId, int ecId, const QJSValue &items_tmp) {
	try {

	if (!m_playlist.clear()) {
		throw m_playlist.errorString();
	}

	for (const AudioTrack &item : items_tmp.toVariant().toList()) {
		this->addItem(scId, ecId, item);
	}

	} catch (const QString &err) {
		this->cb(ecId, err);
	}
}

void RmxAudioPlayer::addItem(int scId, int ecId, const AudioTrack &track) {
	try {

	if (!m_playlist.addMedia(track.assetUrl)) {
		throw m_playlist.errorString();
	}

	} catch (const QString &err) {
		this->cb(ecId, err);
	}
}
