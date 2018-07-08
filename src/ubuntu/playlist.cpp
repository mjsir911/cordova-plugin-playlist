#include "playlist.h"
#include <cordova.h>

RmxAudioPlayer::RmxAudioPlayer(Cordova *cordova): CPlugin(cordova) {
	m_cordova->execJS("console.log('hi')");
}

//void RmxAudioPlayer::create(int scId, int ecId, const QString &id) {
	//objectsDict[id] = QSharedPointer<RmxAudioPlayerItem>(new RmxAudioPlayerItem(id, this));
//}

void RmxAudioPlayer::play(int scId, int ecd) {
	this->cb(scId, "hello");
}
