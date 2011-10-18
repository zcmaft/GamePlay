/*
 * AudioSource.h
 */

#ifndef AUDIOSOURCE_H_
#define AUDIOSOURCE_H_

#include "Vector3.h"
#include "Ref.h"
#include "Node.h"

namespace gameplay
{

class AudioBuffer;
class Node;

/**
 *  Declares an audio source in 3D space.
 */
class AudioSource : public Ref, public Transform::Listener
{
public:

    friend class Node;
    friend class AudioController;

    /**
     * The audio source's audio state.
     */
    enum State
    {
        INITIAL,
        PLAYING,
        PAUSED,
        STOPPED
    };

    /**
     * Create an audio source. This is used to instantiate an Audio Source. Currently only wav, au and raw files are supported.
     *
     * @param path The relative location on disk of the sound file.
     * 
     * @return The newly created audio source, or NULL if an audio source with the given ID already exists.
     */
    static AudioSource* create(const char* path);

    /**
     * Plays the audio source.
     */
    void play();

    /**
     * Pauses the playing of the audio source.
     */
    void pause();

    /**
     * Resumes playing of the audio source.
     */
    void resume();

    /**
     * Stops the playing of the audio source.
     */
    void stop();

    /**
     * Rewinds the audio source to the beginning.
     */
    void rewind();

    /**
     * Gets the current state of the audio source.
     *
     * @return PLAYING if the source is playing, STOPPED if the source is stopped, PAUSED if the source is paused and INITIAL otherwise.
     */
    AudioSource::State getState() const;

    /**
     * Determines whether the audio source is looped or not.
     *
     * @return true if the audio source is looped, false if not.
     */
    bool isLooped() const;

    /**
     * Sets the state of the audio source to be looping or not.
     *
     * @param looped true to loop the sound, false to not loop it.
     */
    void setLooped(bool looped);

    /**
     * Returns the gain of the audio source.
     *
     * @return The gain.
     */
    float getGain() const;

    /**
     * Sets the gain/volume of the audio source.
     *
     * @param gain The gain/volume of the source.
     */
    void setGain(float gain);

    /**
     * Returns the pitch of the audio source.
     *
     * @return The pitch.
     */
    float getPitch() const;

    /**
     * Sets the pitch of the audio source.
     *
     * @param pitch The pitch of the source.
     */
    void setPitch(float pitch);

    /**
     * Gets the velocity of the audio source.
     *
     * @return The velocity as a vector.
     */
    const Vector3& getVelocity() const;

    /**
     * Sets the velocity of the audio source.
     *
     * @param velocity A vector representing the velocity.
     */
    void setVelocity(const Vector3& velocity);

    /**
     * Gets the node that this source is attached to.
     * 
     * @return The node that this audio source is attached to.
     */
    Node* getNode() const;

private:

    /**
     * Constructor that takes an AudioBuffer.
     */
    AudioSource(AudioBuffer* buffer, ALuint source);

    /**
     * Destructor.
     */
    virtual ~AudioSource();

    /**
     * Sets the node for this audio source.
     */
    void setNode(Node* node);

    /**
     * @see Transform::Listener::transformChanged
     */
    void transformChanged(Transform* transform);

    ALuint _alSource;
    AudioBuffer* _buffer;
    bool _looped;
    float _gain;
    float _pitch;
    Vector3 _velocity;
    Node* _node;
};

}

#endif