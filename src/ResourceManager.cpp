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
	namespace // anonymous namespace to simulate "private members"
	{
		/// Unordred map to store textures
		unordered_map<string, Texture> m_textures;
		/// Unordred map to store images
		unordered_map<string, Image> m_images;
		/// Unordred map to store music pointers
		/// @note Pointers because sf::Music is non-copyable
		unordered_map<string, shared_ptr<Music>> m_musics;
		/// Unordred map to store fonts
		unordered_map<string, Font> m_fonts;

		/// @brief Handle loading errors
		/// @param resource The resource that failed to load
		void errorLoading(const string & resource)
		{
			// TODO: open windows API error messagebox for windows users
			std::cerr << "Failed to load \"" << resource << "\"" << std::endl;
			exit(EXIT_FAILURE);
		}

		/// @brief Handle loading errors without cerr message
		void errorLoading()
		{
			// TODO: open windows API error messagebox for windows users
			exit(EXIT_FAILURE);
		}

		/**
		 * @brief Function to load a texture
		 * @param key Name of the texture to load
		 * @param path Path of the texture to load
		*/
		void loadTexture(const string & key, const string & path)
		{
			Texture texture;
			if (!texture.loadFromFile(path))
			{
				errorLoading();
			}
			m_textures[key] = texture;
		}

		/**
		 * @brief Function to load an image
		 * @param key Name of the image to load
		 * @param path Path of the image to load
		*/
		void loadImage(const string & key, const string & path)
		{
			Image image;
			if (!image.loadFromFile(path))
			{
				errorLoading();
			}
			m_images[key] = image;
		}

		/**
		 * @brief Function to load a music
		 * @param key Name of the music to load
		 * @param path Path of the music to load
		*/
		void loadMusic(const string & key, const string & path)
		{
			// pointer to music because sf::Music is non-copyable
			shared_ptr<Music> music = std::make_shared<Music>();
			if (!music->openFromFile(path))
			{
				errorLoading();
			}
			music->setLoop(true);
			m_musics[key] = music;
		}

		/**
		 * @brief Function to load a font
		 * @param key Name of the font to load
		 * @param path Path of the font to load
		*/
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
