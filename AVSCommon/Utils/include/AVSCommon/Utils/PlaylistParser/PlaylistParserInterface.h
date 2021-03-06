/*
 * PlaylistParserInterface.h
 *
 * Copyright 2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *     http://aws.amazon.com/apache2.0/
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#ifndef ALEXA_CLIENT_SDK_AVS_COMMON_UTILS_INCLUDE_AVS_COMMON_UTILS_PLAYLIST_PARSER_PLAYLIST_PARSER_INTERFACE_H_
#define ALEXA_CLIENT_SDK_AVS_COMMON_UTILS_INCLUDE_AVS_COMMON_UTILS_PLAYLIST_PARSER_PLAYLIST_PARSER_INTERFACE_H_

#include <memory>
#include <string>

#include "PlaylistParserObserverInterface.h"

namespace alexaClientSDK {
namespace avsCommon {
namespace utils {
namespace playlistParser {

/**
 * A PlaylistParser parses playlists.
 */
class PlaylistParserInterface {
public:
    /**
     * Destructor.
     */
    virtual ~PlaylistParserInterface() = default;

    /**
     * This function returns immediately. It parses the playlist specified in the @c url asynchronously. The playlist
     * parsing is a DFS parsing. If the playlist contains a link to another playlist, then it will proceed to parse
     * that before proceeding. The result of parsing the playlist is notified to the
     * @c PlaylistParserObserverInterface via the @c onPlaylistParsed call.
     *
     * @param url The url of the playlist to be parsed.
     * @param observer The observer to be notified of when playlist parsing is complete.
     * @return @c true if it was successful in adding a new playlist parsing request to the queue @c else false.
     */
    virtual bool parsePlaylist(const std::string& url, std::shared_ptr<PlaylistParserObserverInterface> observer) = 0;
};

} // namespace playlistParser
} // namespace utils
} // namespace avsCommon
} // namespace alexaClientSDK

#endif // ALEXA_CLIENT_SDK_AVS_COMMON_UTILS_INCLUDE_AVS_COMMON_UTILS_PLAYLIST_PARSER_PLAYLIST_PARSER_INTERFACE_H_
