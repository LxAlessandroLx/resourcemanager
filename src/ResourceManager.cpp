#include "ResourceManager.h"

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>

using std::ifstream;
using std::istringstream;
using std::unordered_map;

namespace ResourceManager
{
	// anonymous namespace to simulate "private members"
	namespace 
	{
		unordered_map<string, Texture> m_textures;
		unordered_map<string, Image> m_images;
		unordered_map<string, shared_ptr<Music>> m_musics;
		unordered_map<string, Font> m_fonts;

		void errorLoading(const string & resource)
		{
			// TODO: open windows API error messagebox for windows users
			std::cerr << "Failed to load \"" << resource << "\"" << std::endl;
			exit(EXIT_FAILURE);
		}

		// errorLoading function overloading for error without cerr message
		void errorLoading()
		{
			// TODO: open windows API error messagebox for windows users
			exit(EXIT_FAILURE);
		}

		void loadTexture(const string & key, const string & path)
		{
			Texture texture;
			if (!texture.loadFromFile(path))
			{
				errorLoading();
			}
			m_textures[key] = texture;
		}

		void loadMusic(const string & key, const string & path)
		{
			// pointer to music because it's not copyable
			shared_ptr<Music> music = std::make_shared<Music>();
			if (!music->openFromFile(path))
			{
				errorLoading();
			}
			music->setLoop(true);
			m_musics[key] = music;
		}

		void loadImage(const string & key, const string & path)
		{
			Image image;
			if (!image.loadFromFile(path))
			{
				errorLoading();
			}
			m_images[key] = image;
		}

		void loadFont(const string & key, const string & path)
		{
			Font font;
			if (!font.loadFromFile(path))
			{
				errorLoading();
			}
			m_fonts[key] = font;
		}
	}

	const Texture & texture(const string & key)
	{
		try
		{
			return m_textures.at(key);
		}
		catch(const std::out_of_range&)
		{
			errorLoading(key);
		}
	}

	const Image & image(const string & key)
	{
		try
		{
			return m_images.at(key);
		}
		catch(const std::out_of_range&)
		{
			errorLoading(key);
		}
	}

	const shared_ptr<Music> music(const string & key)
	{
		try
		{
			return m_musics.at(key);
		}
		catch(const std::out_of_range&)
		{
			errorLoading(key);
		}
	}

	const Font & font(const string & key)
	{
		try
		{
			return m_fonts.at(key);
		}
		catch(const std::out_of_range&)
		{
			errorLoading(key);
		}
	}

	void init()
	{
		// load here your resources
	}
}
