#include "playlist.h"
#include <cordova.h>
#include "AudioTrack.h"

RmxAudioPlayer::RmxAudioPlayer(Cordova *cordova): CPlugin(cordova) {
	m_cordova->execJS("console.log('hi')");
	m_player.setPlaylist(&m_playlist);
}

// These methods don't need a type conversion halfway function

void RmxAudioPlayer::clearAllItems(int scId, int ecId) {
  Q_UNUSED(scId);
	if (!m_playlist.clear()) {
		this->cb(ecId, m_playlist.errorString());
		return;
	}
}

void RmxAudioPlayer::play(int scId, int ecId) {
  Q_UNUSED(scId);
  Q_UNUSED(ecId);
	m_player.play();
}

void RmxAudioPlayer::pause(int scId, int ecId) {
  Q_UNUSED(scId);
  Q_UNUSED(ecId);
	m_player.pause();
}

void RmxAudioPlayer::getPlaybackPosition(int scId, int ecId) {
  Q_UNUSED(ecId);
	this->cb(scId, m_player.position());
}

void RmxAudioPlayer::seekTo(int scId, int ecId, qint64 position) {
  Q_UNUSED(scId);
  Q_UNUSED(ecId);
	this->cb(scId, position);
	m_player.setPosition(position);
}



// These methods have a halfway type conversion function, see below for actual
// implementation

void RmxAudioPlayer::setPlaylistItems(int scId, int ecId, const QJSValue &tracks_tmp) {
  AudioTrackList tracks;
  for (AudioTrack track : tracks_tmp.toVariant().toList()) {
    tracks << track;
  }
  setPlaylistItems(scId, ecId, tracks);
}

void RmxAudioPlayer::addItem(int scId, int ecId, const QJSValue &track) {
	addItem(scId, ecId, AudioTrack(track));
}

void RmxAudioPlayer::addAllItems(int scId, int ecId, const QJSValue &tracks_tmp) {
  AudioTrackList tracks;
  for (AudioTrack track : tracks_tmp.toVariant().toList()) {
    tracks << track;
  }
  addAllItems(scId, ecId, tracks);
}


// type converted functions
int RmxAudioPlayer::setPlaylistItems(int scId, int ecId, const AudioTrackList tracks) {
	if (!m_playlist.clear()) {
		this->cb(ecId, m_playlist.errorString());
		return -1;
	}

	return this->addAllItems(scId, ecId, tracks);
}

int RmxAudioPlayer::addItem(int scId, int ecId, const AudioTrack &track) {
	this->cb(scId, "Hello, world!");
	if (!m_playlist.addMedia(track.assetUrl)) {
		this->cb(ecId, m_playlist.errorString());
		return -1;
	}

	this->cb(scId, track.assetUrl.fileName());
	return 0;
}

int RmxAudioPlayer::addAllItems(int scId, int ecId, const AudioTrackList tracks) {
	for (const AudioTrack &track : tracks) {
		if (!addItem(scId, ecId, track)) {
			return -1;
		}
	}
  return 0;
}
