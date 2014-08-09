#include <glm/gtx/transform.hpp>

#include <gal/std/map.hpp>

#include <gal/log/log.hpp>

#include <neb/core/debug.hh>
#include <neb/core/shape/base.hpp>
#include <neb/core/light/base.hpp>
#include <neb/core/math/geo/polygon.hpp>
#include <neb/core/util/config.hpp>

neb::core::shape::base::base(sp::shared_ptr<neb::core::shape::util::parent> parent):
	parent_(parent),
	s_(1,1,1)
{
	if(DEBUG_NEB) BOOST_LOG_CHANNEL_SEV(lg, "neb core shape", debug) << __FUNCSIG__;
	assert(parent);
}
neb::core::shape::base::~base() {}
neb::core::pose				neb::core::shape::base::getPoseGlobal() {
	if(DEBUG_NEB) BOOST_LOG_CHANNEL_SEV(lg, "neb core shape", debug) << __FUNCSIG__;
	
	neb::core::pose m;
	
	auto parent = parent_.lock();
	if(parent) {
		m = parent->getPoseGlobal() * getPose();
	} else {
		m = getPose();
	}

	return m;
}
neb::core::pose				neb::core::shape::base::getPose() {
	return pose_;
}
void					neb::core::shape::base::init() {
	if(DEBUG_NEB) BOOST_LOG_CHANNEL_SEV(lg, "neb core shape", debug) << __FUNCSIG__;

	auto me = sp::dynamic_pointer_cast<neb::core::shape::base>(shared_from_this());
	//auto scene = get_parent()->get_scene();

	// type

	// program
/*	if(image_.length() == 0) {
		program_ = neb::program_name::LIGHT;
	} else {
		** @todo replace this with something better... *
		//flag_.set(neb::core::shape::flag::e::IMAGE);

		program_ = neb::program_name::IMAGE;
	}
*/

	neb::core::shape::util::parent::init();
	neb::core::light::util::parent::init();

}
void					neb::core::shape::base::release() {
	if(DEBUG_NEB) BOOST_LOG_CHANNEL_SEV(lg, "neb core shape", debug) << __FUNCSIG__;

	//neb::util::parent<neb::core::shape::base>::release();
	neb::core::shape::util::parent::release();
	neb::core::light::util::parent::release();
}
void							neb::core::shape::base::step(gal::std::timestep const & ts) {

	neb::core::shape::util::parent::step(ts);

	neb::core::light::util::parent::step(ts);

}
sp::weak_ptr<neb::core::light::base>			neb::core::shape::base::createLightPoint() {
	return sp::weak_ptr<neb::core::light::base>();
}

