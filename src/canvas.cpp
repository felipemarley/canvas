/*!
 * Canvas class implementation.
 * @file canvas.cpp
 */

#include "canvas.h"

namespace life {

  // TODO: Adicione o resto da implementação dos métodos aqui.

  Canvas::Canvas(size_t w, size_t h, short bs){
    this->m_width = w;
    this->m_height = h;
    this->m_block_size = bs;
    //ignoring bs
    this->m_pixels.resize(w*h*4);
  }
    /// Destructor.
  Canvas::~Canvas(void) = default;
    /// Copy constructor.
  //Canvas::Canvas(const Canvas&) = default;
  /// Assignment operator.
  //Canvas& Canvas::operator=(const Canvas&) = default;

  //=== Members
  /// Clear the canvas with black color.
  void Canvas::clear(const Color& color){
    for(size_t i{0u}; i < m_pixels.size(); i+=4){
      m_pixels[i] = color.channels[Color::R]; 
      m_pixels[i + 1] = color.channels[Color::G];
      m_pixels[i + 2] = color.channels[Color::B];
      m_pixels[i + 3] = 255;
    }
  }
  /// Set the color of a pixel on the canvas.
  void Canvas::pixel(coord_t x, coord_t y, const Color& color){
      m_pixels[(y*m_width*4) + (x*4)] = color.channels[Color::R]; 
      m_pixels[(y*m_width*4) + (x*4) + 1] = color.channels[Color::G];
      m_pixels[(y*m_width*4) + (x*4) + 2] = color.channels[Color::B];
      m_pixels[(y*m_width*4) + (x*4) + 3] = 255;

  }
  /// Get the pixel color from the canvas.
  Color Canvas::pixel(coord_t, coord_t) const{return BLACK;}

}  // namespace life

//================================[ canvas.cpp ]================================//
