
#include "Texture.h"

Texture::Texture()
{
    this->id = 0;
    this->width = 0;
	this->height = 0;
	this->filename = "";
}

Texture::Texture(std::string filename)
{
    this->id = 0;
    this->width = 0;
	this->height = 0;
	this->filename = "";
    Load(filename);
}

Texture::~Texture()
{
    Delete();
}

void Texture::Load(std::string filename)
{
    SDL_Surface *surface = IMG_Load(filename.c_str());
    
    if (surface) {
        GLuint texture;
        GLenum format;
        GLint  channels;
        
        channels = surface->format->BytesPerPixel;
        if (channels == 4) {
            format = surface->format->Rmask == 0x000000ff ? 
                GL_RGBA : GL_BGRA;
        } else if (channels == 3) {
            format = surface->format->Rmask == 0x000000ff ? 
                GL_RGB : GL_BGR;
        } else {
            std::cerr << "SDL: Invalid channels '" << channels << "'" << std::endl;
            SDL_FreeSurface(surface);
            return;
        }
        
        this->filename = filename;
        this->height = surface->h;
        this->width = surface->w;

        glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
        glTexImage2D(GL_TEXTURE_2D, 0, channels, this->width, this->height, 0,
            format, GL_UNSIGNED_BYTE, surface->pixels);
        
        // flip the image.
        glMatrixMode(GL_TEXTURE);
        glLoadIdentity();
        glTranslatef(0.5f, 0.5f, 0.0f);
        glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
        glTranslatef(-0.5f, -0.5f, 0.0f);
        glMatrixMode(GL_MODELVIEW);
        
        if (this->id) {
            glDeleteTextures(1, &this->id);
        }
		this->id = texture;
		
		SDL_FreeSurface(surface);
	} else {
	    std::cerr << "SDL: Cant load image '" << filename << "'" << std::endl;
	}
}

void Texture::Reload()
{
    if (this->filename != "") {
        Load(this->filename);
    }
}

void Texture::Delete()
{
    if (this->id) {
        glDeleteTextures(1, &this->id);
        this->id = 0;
    }
}

void Texture::Draw(GLint x, GLint y) 
{
    if (this->id < 1) {
        return;
    }

    glPushMatrix();
    
    glBindTexture(GL_TEXTURE_2D, this->id);
    glTranslatef(x, y, 0.0f);

    glBegin(GL_QUADS);
    
	//Bottom-left vertex
	glTexCoord2i(0, 0);
	glVertex2f(0, height);
 
	//Bottom-right vertex
	glTexCoord2i(1, 0);
	glVertex2f(width, height);
 
	//Top-right vertex
	glTexCoord2i(1, 1);
	glVertex2f(width, 0);
 
	//Top-left vertex
	glTexCoord2i(0, 1);
	glVertex2f(0, 0);
	
    glEnd();
    
    glPopMatrix();
}
