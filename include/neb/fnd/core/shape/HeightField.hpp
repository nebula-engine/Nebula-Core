#ifndef NEB_CORE_CORE_SHAPE_HEIGHT_FIELD_HPP
#define NEB_CORE_CORE_SHAPE_HEIGHT_FIELD_HPP

#include <neb/fnd/core/shape/base.hpp>
#include <neb/fnd/core/shape/HeightField/desc.hpp>

namespace neb { namespace fnd { namespace core { namespace shape { namespace HeightField {
	class Base:
		virtual public neb::fnd::core::shape::base
	{
	public:
		typedef neb::fnd::core::shape::util::parent parent_t;
		Base();
		virtual void				init(parent_t * const & p);
		virtual void				release();
		virtual void				step(gal::etc::timestep  const & ts);
		virtual void	load(ba::polymorphic_iarchive & ar, unsigned int const &);
		virtual void	save(ba::polymorphic_oarchive & ar, unsigned int const &) const;
		float				min_y_;
		float				max_y_;
		neb::fnd::core::shape::HeightField::desc	desc_;
	};



}}}}}


#endif


