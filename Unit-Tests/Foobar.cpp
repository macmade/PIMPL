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
 * @brief       Test class Foobar
 */

#include "Foobar.hpp"
#include "Foo.hpp"

template<>
class XS::PIMPL::Object< Foobar >::IMPL
{
    public:
        
        IMPL( void )
        {}
        
        IMPL( int x, int y ): _foo( x, y )
        {}
        
        IMPL( const IMPL & o ): _foo( o._foo )
        {}
        
        ~IMPL( void )
        {}
        
        Foo _foo;
};

#define XS_PIMPL_CLASS Foobar
#include <XS/PIMPL/Object-IMPL.hpp>

Foobar::Foobar( void ): XS::PIMPL::Object< Foobar >()
{}

Foobar::Foobar( int x, int y ): XS::PIMPL::Object< Foobar >( x, y )
{}

int Foobar::GetX( void )
{
    return this->impl->_foo.GetX();
}

int Foobar::GetY( void )
{
    return this->impl->_foo.GetY();
}

void Foobar::SetX( int x )
{
    this->impl->_foo.SetX( x );
}

void Foobar::SetY( int y )
{
    this->impl->_foo.SetY( y );
}
