#ifndef NEB_CORE_CORE_ACTOR_RIGIDDYNAMIC_DESC_HPP
#define NEB_CORE_CORE_ACTOR_RIGIDDYNAMIC_DESC_HPP

#include <boost/serialization/split_member.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>

#include <gal/itf/shared.hpp>

#include <neb/core/pose.hpp>
#include <neb/core/core/shape/desc.hpp>
#include <neb/core/core/actor/rigidbody/desc.hpp>

namespace neb { namespace core { namespace core { namespace actor { namespace rigiddynamic {

	struct desc: neb::core::core::actor::rigidbody::desc
	{
		desc();
		desc(neb::core::pose npose);
		template<class Archive> void		__load(Archive & ar, unsigned int const & version)
		{
			//ar & boost::serialization::make_nvp("foo",foo);
		}
		template<class Archive> void		__save(Archive & ar, unsigned int const & version) const
		{
			//ar & boost::serialization::make_nvp("foo",foo);
		}
		virtual void				load(
				boost::archive::xml_iarchive & ar,
				unsigned int const & version);
		virtual void				save(
				boost::archive::xml_oarchive & ar,
				unsigned int const & version) const;
		
		virtual std::shared_ptr<neb::core::core::actor::base>		visit(
				neb::core::core::scene::base * const scene
				) const;

		BOOST_SERIALIZATION_SPLIT_MEMBER();


	};

}}}}}

#endif
