#ifndef LOCK_AUDIOTRACKREMOVAL_H
#define LOCK_AUDIOTRACKREMOVAL_H

#include <QString>

/**
 * Encapsulates the fields you can pass to the plugin to remove a track.
 * You can either remove a track by its ID if you know it, or by index if you know it;
 * Index will be preferred if both index and ID are passed.
 */
//export interface AudioTrackRemoval {
struct AudioTrackRemoval {
  /**
   * The track ID to remove
   */
  //trackId?: string;
  const QString trackId;
  /**
   * The index of a track to remove.
   */
  // trackIndex?: number;
	const unsigned int trackIndex;

	AudioTrackRemoval (const unsigned int trackIndex, const QString trackId): trackId(trackId)
	                                                                        , trackIndex(trackIndex)
	{}

	AudioTrackRemoval (const QVariantMap &map): AudioTrackRemoval(map.value("trackIndex").toInt(),
	                                                              map.value("trackId"   ).toString())
	{}

	AudioTrackRemoval (const QVariant &item): AudioTrackRemoval(item.toMap()) {}
	AudioTrackRemoval (const QJSValue &item): AudioTrackRemoval(item.toVariant()) {}
};


#endif
