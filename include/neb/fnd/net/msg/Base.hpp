#ifndef NEBULA_MESSAGE_BASE_HPP
#define NEBULA_MESSAGE_BASE_HPP

#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>

#include <gal/itf/shared.hpp>
#include <gal/net/message.hpp>

#include <neb/fnd/net/msg/util/decl.hpp>

namespace neb { namespace fnd { namespace net { namespace msg {
	/** \brief %Base
	 */
	class Base:
		//virtual public gal::type_info<neb::fnd::net::msg::Base>
		virtual public gal::itf::shared
	{
	protected:
		Base();
	public:
		virtual ~Base();
		virtual	void			release();
		virtual void			load(
				boost::archive::polymorphic_iarchive & ar,
				unsigned int const & version) = 0;	
		virtual void			save(
				boost::archive::polymorphic_oarchive & ar,
				unsigned int const & version) const = 0;
		BOOST_SERIALIZATION_SPLIT_MEMBER();
		std::shared_ptr<gal::net::message>	msg_;
	};
}}}}

#endif

/** \example Nebula/message/example.cc
 * Example.
 */


