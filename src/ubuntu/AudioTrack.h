#ifndef LOCK_AUDIOTRACK_H
#define LOCK_AUDIOTRACK_H

#include <QString>

struct AudioTrack {

  /**
   * This item is a streaming asset. Make sure this is set to true for stream URLs,
   * otherwise you will get odd behavior when the asset is paused.
   */
  const bool isStream;

  /**
   * trackId is optional and if not passed in, an auto-generated UUID will be used.
   */
  const QString trackId;

  /**
   * URL of the asset; can be local, a URL, or a streaming URL.
   * If the asset is a stream, make sure that isStream is set to true,
   * otherwise the plugin can't properly handle the item's buffer.
   */
  const QUrl assetUrl;

  /**
   * The local or remote URL to an image asset to be shown for this track.
   * If this is null, the plugin's default image is used.
   * This field is not used on iOS (yet)
   */
  const QUrl albumArt;

  /**
   * The track's artist
   */
  const QString artist;

  /**
   * Album the track belongs to
   */
  const QString album;

  /**
   * Title of the track
   */
  const QString title;



	AudioTrack (const QVariantMap& item): isStream(item.value("isStream").toBool())
	                                    , trackId( item.value("trackId" ).toString())
	                                    , assetUrl(item.value("assetUrl").toString())
	                                    , albumArt(item.value("albumArt").toString())
	                                    , artist(  item.value("artist"  ).toString())
	                                    , album(   item.value("album"   ).toString())
	                                    , title(   item.value("title"   ).toString())
	{}
};


#endif
