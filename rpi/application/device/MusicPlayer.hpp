/*
 * MusicPlayer.hpp
 *
 *  Created on: Jul 17, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_DEVICE_MUSICPLAYER_HPP_
#define APPLICATION_DEVICE_MUSICPLAYER_HPP_
#include <string>
#include <list>
#include <utils/Logger/Logger.hpp>

#include <alsa/asoundlib.h>

namespace device {
#define PCM_DEVICE "default"
enum PlayerState
{
	playing,
	stopped,
	configured,
  failedOnConfiguration,
	unconfigured
};

class MusicPlayer
{
public:
	MusicPlayer();
	void initialize();

	void stop();
	void play(std::string);

  void pause(){}
  void resume(){}

	PlayerState getState();

	virtual ~MusicPlayer();
private:
  u32 buff_size;
  snd_pcm_t *pcm_handle;
  snd_pcm_hw_params_t *params;
	PlayerState state;
};

} /* namespace device */

#endif /* APPLICATION_DEVICE_MUSICPLAYER_HPP_ */
