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
 * @brief       Test class Bar
 */

#include "Bar.hpp"

template<>
class XS::PIMPL::Object< Bar >::IMPL
{
    public:
        
        IMPL( void ): _z( 0 )
        {}
        
        IMPL( int z ): _z( z )
        {}
        
        IMPL( const IMPL & o ): _z( o._z )
        {}
        
        ~IMPL( void )
        {}
        
        int _z;
};

#define XS_PIMPL_CLASS Bar
#include <XS/PIMPL/Object-IMPL.hpp>

Bar::Bar( void ): Foo( 0, 0 ), XS::PIMPL::Object< Bar >( 0 )
{}

Bar::Bar( int x, int y, int z ): Foo( x, y ), XS::PIMPL::Object< Bar >( z )
{}

int Bar::GetZ( void )
{
    return this->impl->_z;
}

void Bar::SetZ( int z )
{
    this->impl->_z = z;
}
