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
 * @brief       Test case XS::PIMPL::Object
 */

#ifdef _WIN32
#define XSTEST_MAIN
#endif

#define XSTEST_GTEST_COMPAT
#include <XSTest/XSTest.hpp>
#include "Foo.hpp"
#include "Bar.hpp"
#include "Foobar.hpp"

using namespace testing;

TEST( XS_PIMPL_Object, FooClassGetter )
{
    Foo f;
    
    ASSERT_EQ( 0, f.GetX() );
    ASSERT_EQ( 0, f.GetY() );
}

TEST( XS_PIMPL_Object, FooClassSetter )
{
    Foo f;
    
    f.SetX( 1 );
    f.SetY( 2 );
    
    ASSERT_EQ( 1, f.GetX() );
    ASSERT_EQ( 2, f.GetY() );
}

TEST( XS_PIMPL_Object, FooClassConstructorWithParams )
{
    Foo f( 1, 2 );
    
    ASSERT_EQ( 1, f.GetX() );
    ASSERT_EQ( 2, f.GetY() );
}

TEST( XS_PIMPL_Object, FooClassCopyConstructor )
{
    Foo f1( 1, 2 );
    Foo f2( f1 );
    
    ASSERT_EQ( 1, f2.GetX() );
    ASSERT_EQ( 2, f2.GetY() );
}

TEST( XS_PIMPL_Object, FooClassMoveConstructor )
{
    Foo f1( 1, 2 );
    Foo f2 = std::move( f1 );
    
    ASSERT_EQ( 1, f2.GetX() );
    ASSERT_EQ( 2, f2.GetY() );
}

TEST( XS_PIMPL_Object, FooClassAssigmnentOperator )
{
    Foo f1( 1, 2 );
    Foo f2;
    
    f2 = f1;
    
    ASSERT_EQ( 1, f2.GetX() );
    ASSERT_EQ( 2, f2.GetY() );
}

TEST( XS_PIMPL_Object, BarClassGetter )
{
    Bar b;
    
    ASSERT_EQ( 0, b.GetX() );
    ASSERT_EQ( 0, b.GetY() );
    ASSERT_EQ( 0, b.GetZ() );
}

TEST( XS_PIMPL_Object, BarClassSetter )
{
    Bar b;
    
    b.SetX( 1 );
    b.SetY( 2 );
    b.SetZ( 3 );
    
    ASSERT_EQ( 1, b.GetX() );
    ASSERT_EQ( 2, b.GetY() );
    ASSERT_EQ( 3, b.GetZ() );
}

TEST( XS_PIMPL_Object, BarClassConstructorWithParams )
{
    Bar b( 1, 2, 3 );
    
    ASSERT_EQ( 1, b.GetX() );
    ASSERT_EQ( 2, b.GetY() );
    ASSERT_EQ( 3, b.GetZ() );
}

TEST( XS_PIMPL_Object, BarClassCopyConstructor )
{
    Bar b1( 1, 2, 3 );
    Bar b2( b1 );
    
    ASSERT_EQ( 1, b2.GetX() );
    ASSERT_EQ( 2, b2.GetY() );
    ASSERT_EQ( 3, b2.GetZ() );
}

TEST( XS_PIMPL_Object, BarClassMoveConstructor )
{
    Bar b1( 1, 2, 3 );
    Bar b2 = std::move( b1 );
    
    ASSERT_EQ( 1, b2.GetX() );
    ASSERT_EQ( 2, b2.GetY() );
    ASSERT_EQ( 3, b2.GetZ() );
}

TEST( XS_PIMPL_Object, BarClassAssigmnetOperator )
{
    Bar b1( 1, 2, 3 );
    Bar b2;
    
    b2 = b1;
    
    ASSERT_EQ( 1, b2.GetX() );
    ASSERT_EQ( 2, b2.GetY() );
    ASSERT_EQ( 3, b2.GetZ() );
}

TEST( XS_PIMPL_Object, FoobarClassGetter )
{
    Foobar f;
    
    ASSERT_EQ( 0, f.GetX() );
    ASSERT_EQ( 0, f.GetY() );
}

TEST( XS_PIMPL_Object, FoobarClassSetter )
{
    Foobar f;
    
    f.SetX( 1 );
    f.SetY( 2 );
    
    ASSERT_EQ( 1, f.GetX() );
    ASSERT_EQ( 2, f.GetY() );
}

TEST( XS_PIMPL_Object, FoobarClassConstructorWithParams )
{
    Foobar f( 1, 2 );
    
    ASSERT_EQ( 1, f.GetX() );
    ASSERT_EQ( 2, f.GetY() );
}

TEST( XS_PIMPL_Object, FoobarClassCopyConstructor )
{
    Foobar f1( 1, 2 );
    Foobar f2( f1 );
    
    ASSERT_EQ( 1, f2.GetX() );
    ASSERT_EQ( 2, f2.GetY() );
}

TEST( XS_PIMPL_Object, FoobarClassMoveConstructor )
{
    Foobar f1( 1, 2 );
    Foobar f2 = std::move( f1 );
    
    ASSERT_EQ( 1, f2.GetX() );
    ASSERT_EQ( 2, f2.GetY() );
}

TEST( XS_PIMPL_Object, FoobarClassAssigmnentOperator )
{
    Foobar f1( 1, 2 );
    Foobar f2;
    
    f2 = f1;
    
    ASSERT_EQ( 1, f2.GetX() );
    ASSERT_EQ( 2, f2.GetY() );
}
