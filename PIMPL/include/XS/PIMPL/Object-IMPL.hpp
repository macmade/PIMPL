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
 * @brief       Private delcarations of the XS::PIMPL::Object template class
 * 
 * This header shall be included in implementations of PIMPL classes.
 * Note that explicit template instanciation is required after the declaration
 * of the IMPL class.
 */

#include <XS/PIMPL/Object.hpp>
#include <memory>
#include <algorithm>

#ifndef XS_PIMPL_CLASS
#error "Please define XS_PIMPL_CLASS before including this header file"
#endif

namespace XS
{
    namespace PIMPL
    {
        /* C++11 support is buggy on MSVC V120 toolset (see C4520)... */
        #if !defined( _MSC_FULL_VER ) || _MSC_FULL_VER >= 190024215
        
        template<>
        Object< XS_PIMPL_CLASS >::Object( void ): impl( new Object< XS_PIMPL_CLASS >::IMPL() )
        {}
        
        template<>
        template< typename ... A >
        Object< XS_PIMPL_CLASS >::Object( A & ... a ): impl( new Object< XS_PIMPL_CLASS >::IMPL( a ... ) )
        {}
        
        template<>
        template< typename ... A >
        Object< XS_PIMPL_CLASS >::Object( const A & ... a ): impl( new Object< XS_PIMPL_CLASS >::IMPL( a ... ) )
        {}
        
        #else
        
        template<>
        Object< XS_PIMPL_CLASS >::Object( void ): impl( new Object< XS_PIMPL_CLASS >::IMPL )
        {}
        
        template<>
        template< typename A1, typename ... A2 >
        Object< XS_PIMPL_CLASS >::Object( A1 a1, A2 ... a2 ): impl( new Object< XS_PIMPL_CLASS >::IMPL( a1, a2 ... ) )
        {}
        
        #endif
        
        template<>
        Object< XS_PIMPL_CLASS >::Object( const Object< XS_PIMPL_CLASS > & o ): impl( new Object< XS_PIMPL_CLASS >::IMPL( *( o.impl ) ) )
        {}
        
        template<>
        Object< XS_PIMPL_CLASS >::Object( Object< XS_PIMPL_CLASS > && o ): impl( std::move( o.impl ) )
        {
            o.impl = nullptr;
        }
        
        template<>
        Object< XS_PIMPL_CLASS >::~Object( void )
        {
            delete this->impl;
        }
        
        template<>
        Object< XS_PIMPL_CLASS > & Object< XS_PIMPL_CLASS >::operator =( Object< XS_PIMPL_CLASS > o )
        {
            swap( *( this ), o );
            
            return *( this );
        }
        
        template< class U >
        void swap( Object< U > & o1, Object< U > & o2 )
        {
            using std::swap;
            
            swap( o1.impl, o2.impl );
        }
    }
}

/* Explicit template instantiation */
template class XS::PIMPL::Object< XS_PIMPL_CLASS >;
template void XS::PIMPL::swap< XS_PIMPL_CLASS >( XS::PIMPL::Object< XS_PIMPL_CLASS > & o1, XS::PIMPL::Object< XS_PIMPL_CLASS > & o2 );
