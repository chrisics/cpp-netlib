#ifndef BOOST_NETWORK_PROTOCOL_HTTP_MESSAGE_DIRECTIVES_URI_HPP_20100620
#define BOOST_NETWORK_PROTOCOL_HTTP_MESSAGE_DIRECTIVES_URI_HPP_20100620

// Copyright 2010 (c) Dean Michael Berris
// Copyright 2010 (c) Sinefunc, Inc.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/network/tags.hpp>
#include <boost/network/traits/string.hpp>

namespace boost { namespace network { namespace http {

    template <class Tag>
    class basic_request;

    namespace impl {

        template <class Tag>
        struct uri_directive {

            typedef typename string<Tag>::type string_type;

            string_type uri_;

            explicit uri_directive(string_type const & uri)
                : uri_(uri) {}

            uri_directive(uri_directive const & other)
                : uri_(other.uri_) {}

            template <class T> basic_request<T> const & operator() (basic_request<T> const & request) const {
                request.uri(uri_);
                return request;
            }

        };

    } // namespace impl

    inline impl::uri_directive<tags::default_> const uri(string<tags::default_>::type const & uri_) {
        return impl::uri_directive<tags::default_>(uri_);
    }

} // namespace http

} // namespace network 

} // namespace boost

#endif // BOOST_NETWORK_PROTOCOL_HTTP_MESSAGE_DIRECTIVES_URI_HPP_20100620