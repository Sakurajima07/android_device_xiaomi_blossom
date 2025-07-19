#pragma once

#include <media/AudioTrack.h>

using namespace android;

class LegacyCallbackWrapper : public AudioTrack::IAudioTrackCallback {
public:
    void (*mCallback)(int event, void* user, void *info);
    void* const mData;

public:
    LegacyCallbackWrapper(void (*callback)(int event, void* user, void *info), void *user)  : mCallback(callback), mData(user) {}
  size_t onMoreData(const AudioTrack::Buffer &buffer) override {
    AudioTrack::Buffer copy = buffer;
    mCallback(AudioTrack::EVENT_MORE_DATA, mData, static_cast<void *>(&copy));
    return copy.size();
  }
  void onUnderrun() override {
    mCallback(AudioTrack::EVENT_UNDERRUN, mData, nullptr);
  }
  void onLoopEnd(int32_t loopsRemaining) override {
    mCallback(AudioTrack::EVENT_LOOP_END, mData, &loopsRemaining);
  }
  void onMarker(uint32_t markerPosition) override {
    mCallback(AudioTrack::EVENT_MARKER, mData, &markerPosition);
  }
  void onNewPos(uint32_t newPos) override {
    mCallback(AudioTrack::EVENT_NEW_POS, mData, &newPos);
  }
  void onBufferEnd() override {
    mCallback(AudioTrack::EVENT_BUFFER_END, mData, nullptr);
  }
  void onNewIAudioTrack() override {
    mCallback(AudioTrack::EVENT_NEW_IAUDIOTRACK, mData, nullptr);
  }
  void onStreamEnd() override {
    mCallback(AudioTrack::EVENT_STREAM_END, mData, nullptr);
  }
  size_t onCanWriteMoreData(const AudioTrack::Buffer &buffer) override {
    AudioTrack::Buffer copy = buffer;
    mCallback(AudioTrack::EVENT_CAN_WRITE_MORE_DATA, mData,
              static_cast<void *>(&copy));
    return copy.size();
  }
};
