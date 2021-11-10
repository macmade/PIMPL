/*******************************************************************************
 * The MIT License (MIT)
 * 
 * Copyright (c) 2015 Jean-David Gadina - www.xs-labs.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

/*!
 * @copyright   (c) 2015 - Jean-David Gadina - www.xs-labs.com
 * @brief       Test class Foo
 */

#include "Foo.hpp"

template<>
class XS::PIMPL::Object< Foo >::IMPL
{
    public:
        
        IMPL( void ): _x( 0 ), _y( 0 )
        {}
        
        IMPL( int x, int y ): _x( x ), _y( y )
        {}
        
        IMPL( const IMPL & o ): _x( o._x ), _y( o._y )
        {}
        
        ~IMPL( void )
        {}
        
        int _x;
        int _y;
};

#define XS_PIMPL_CLASS Foo
#include <XS/PIMPL/Object-IMPL.hpp>

Foo::Foo( void ): XS::PIMPL::Object< Foo >( 0, 0 )
{}

Foo::Foo( int x, int y ): XS::PIMPL::Object< Foo >( x, y )
{}

int Foo::GetX( void )
{
    return this->impl->_x;
}

int Foo::GetY( void )
{
    return this->impl->_y;
}

void Foo::SetX( int x )
{
    this->impl->_x = x;
}

void Foo::SetY( int y )
{
    this->impl->_y = y;
}
