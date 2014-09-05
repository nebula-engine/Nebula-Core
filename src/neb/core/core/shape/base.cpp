#include <glm/gtx/transform.hpp>

#include <gal/stl/map.hpp>

#include <gal/log/log.hpp>

#include <neb/core/math/geo/polygon.hpp>
#include <neb/core/util/config.hpp>
#include <neb/core/util/log.hpp>
#include <neb/core/util/debug.hpp>
#include <neb/core/core/shape/base.hpp>
#include <neb/core/core/light/base.hpp>

neb::core::core::shape::base::base():
	scale_(1.0)
{
	LOG(lg, neb::core::core::shape::sl, debug) << __FUNCSIG__;
}
neb::core::core::shape::base::~base()
{
	LOG(lg, neb::core::core::shape::sl, info) << __FUNCSIG__;
}
neb::core::pose				neb::core::core::shape::base::getPoseGlobal() const {
	LOG(lg, neb::core::core::shape::sl, debug) << __FUNCSIG__;
	
	return getParent()->getPoseGlobal() * pose_;
}
neb::core::pose				neb::core::core::shape::base::getPose() const {
	return pose_;
}
void					neb::core::core::shape::base::init() {
	LOG(lg, neb::core::core::shape::sl, debug) << __FUNCSIG__;

	auto me = std::dynamic_pointer_cast<neb::core::core::shape::base>(shared_from_this());
	//auto scene = get_parent()->get_scene();

	// type

	// program
	/*	if(image_.length() == 0) {
		program_ = neb::program_name::LIGHT;
		} else {
	 ** @todo replace this with something better... *
	//flag_.set(neb::core::core::shape::flag::e::IMAGE);

	program_ = neb::program_name::IMAGE;
	}
	*/

	neb::core::core::shape::util::parent::init();
	neb::core::core::light::util::parent::init();

}
void					neb::core::core::shape::base::release() {
	LOG(lg, neb::core::core::shape::sl, debug) << __FUNCSIG__;

	neb::core::core::shape::util::parent::map_.clear();
	neb::core::core::light::util::parent::map_.clear();
}
void						neb::core::core::shape::base::step(
		gal::etc::timestep const & ts)
{
	neb::core::core::shape::util::parent::step(ts);
	neb::core::core::light::util::parent::step(ts);
}

