//#ifndef GLI_H
//#define GLI_H
//
//#include <assert.h>
//#include <GL\glew.h>
//#include <gli.hpp>
//
//gli::texture2D Texture(gli::loadStorageDDS("kueken2.dds"));
//assert(!Texture.empty());
//glBindTexture(GL_TEXTURE_2D, TextureName);
//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, GLint(Texture.levels() - 1));
//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_R, GL_RED);
//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_G, GL_GREEN);
//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_B, GL_BLUE);
//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_A, GL_ALPHA);
//glTexStorage2D(GL_TEXTURE_2D,
//GLint(Texture.levels()),
//GLenum(gli::internal_format(Texture.format())),
//GLsizei(Texture.dimensions().x),
//GLsizei(Texture.dimensions().y));
//if(gli::is_compressed(Texture.format()))
//{
//	for(gli::texture2D::size_type Level = 0; Level < Texture.levels(); ++Level)
//	{
//	glCompressedTexSubImage2D(GL_TEXTURE_2D,
//	GLint(Level),
//	0, 0,
//	GLsizei(Texture[Level].dimensions().x),
//	GLsizei(Texture[Level].dimensions().y),
//	GLenum(gli::internal_format(Texture.format())),
//	GLsizei(Texture[Level].size()),
//	Texture[Level].data());
//	}
//}
//else
//{
//for(gli::texture2D::size_type Level = 0; Level < Texture.levels(); ++Level)
//{
//glTexSubImage2D(GL_TEXTURE_2D,
//GLint(Level),
//0, 0,
//GLsizei(Texture[Level].dimensions().x),
//GLsizei(Texture[Level].dimensions().y),
//GLenum(gli::external_format(Texture.format())),
//GLenum(gli::type_format(Texture.format())),
//Texture[Level].data());
//}
//}
//
//#endif