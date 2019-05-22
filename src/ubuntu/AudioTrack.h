#ifndef LOCK_AUDIOTRACK_H
#define LOCK_AUDIOTRACK_H

#include <QJSValue>
#include <QList>
#include <QString>

struct AudioTrack {

  /**
   * This item is a streaming asset. Make sure this is set to true for stream URLs,
   * otherwise you will get odd behavior when the asset is paused.
   */
  bool isStream;

  /**
   * trackId is optional and if not passed in, an auto-generated UUID will be used.
   */
  QString trackId;

  /**
   * URL of the asset; can be local, a URL, or a streaming URL.
   * If the asset is a stream, make sure that isStream is set to true,
   * otherwise the plugin can't properly handle the item's buffer.
   */
  QUrl assetUrl;

  /**
   * The local or remote URL to an image asset to be shown for this track.
   * If this is null, the plugin's default image is used.
   * This field is not used on iOS (yet)
   */
  QUrl albumArt;

  /**
   * The track's artist
   */
  QString artist;

  /**
   * Album the track belongs to
   */
  QString album;

  /**
   * Title of the track
   */
  QString title;



	AudioTrack (const QVariantMap &item): isStream(item.value("isStream").toBool())
	                                    , trackId( item.value("trackId" ).toString())
	                                    , assetUrl(item.value("assetUrl").toString())
	                                    , albumArt(item.value("albumArt").toString())
	                                    , artist(  item.value("artist"  ).toString())
	                                    , album(   item.value("album"   ).toString())
	                                    , title(   item.value("title"   ).toString())
	{}

	AudioTrack (const QVariant  item): AudioTrack(item.toMap()) {}
	AudioTrack (const QJSValue  item): AudioTrack(item.toVariant()) {}
};

typedef QList<AudioTrack> AudioTrackList;

#endif
