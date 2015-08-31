/*******************************************************************************
 * Copyright (c) 2015, Jean-David Gadina - www.xs-labs.com
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
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
