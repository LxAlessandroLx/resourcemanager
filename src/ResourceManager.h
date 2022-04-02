#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <memory>

#ifdef _WIN32
#include <windows.h>
#endif

using sf::Texture;
using sf::Music;
using sf::Image;
using sf::Font;
using std::string;
using std::shared_ptr;

namespace ResourceManager
{
	/** 
	 * @brief Function to get a texture from loaded textures
	 * @param key texture name
	 * @return Const reference to the texture 
	*/
	const Texture & texture(const string & key);

	/** 
	 * @brief Function to get an image from loaded images
	 * @param key image name
	 * @return Const reference to the image
	*/
	const Image & image(const string & key);

	/** 
	 * @brief Function to get a music from loaded musics
	 * @param key music name
	 * @return Pointer to the music
	*/
	const shared_ptr<Music> music(const string & key);

	/** 
	 * @brief Function to get a font from loaded font
	 * @param key font name
	 * @return Const reference to the font
	*/
	const Font & font(const string & key);

	/// @brief Function to init resources
	void init();
};

#endif // RESOURCEMANAGER_H
