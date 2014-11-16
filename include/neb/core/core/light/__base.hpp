#ifndef NEBULA_CORE_LIGHT___BASE_HPP
#define NEBULA_CORE_LIGHT___BASE_HPP

#include <gal/stl/child.hpp>

#include <neb/core/core/light/util/decl.hpp>
#include <neb/core/itf/shared.hpp>
#include <neb/core/itf/serializable.hpp>

namespace neb { namespace core { namespace core { namespace light {

	class __base:
		virtual public neb::core::itf::shared,
		virtual public neb::core::itf::serializable,
		virtual public gal::stl::child<neb::core::core::light::util::parent>
	{
		public:
			virtual void		init(neb::core::core::light::util::parent * const & p) = 0;
			virtual void		callbackPose(neb::core::math::pose const &) = 0;

			virtual void		load(ba::polymorphic_iarchive & ar, unsigned int const &) = 0;
			virtual void		save(ba::polymorphic_oarchive & ar, unsigned int const &) const = 0;
			BOOST_SERIALIZATION_SPLIT_MEMBER();

	};

}}}}

#endif
