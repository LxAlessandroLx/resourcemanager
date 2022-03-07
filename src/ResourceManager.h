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
	const Texture & texture(const string & key);
	const Image & image(const string & key);
	const shared_ptr<Music> music(const string & key);
	const Font & font(const string & key);

	void init();
};

#endif
