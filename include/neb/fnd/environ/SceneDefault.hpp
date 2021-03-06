#ifndef NEBULA_FND_ENVIRON_SCENE_DEF_HPP
#define NEBULA_FND_ENVIRON_SCENE_DEF_HPP

#include <neb/fnd/core/actor/util/decl.hpp>
#include <neb/fnd/environ/Three.hpp>
#include <neb/fnd/environ/Single.hpp>
#include <neb/fnd/camera/util/decl.hpp>

namespace neb { namespace fnd { namespace environ {
	/** @brief base
	 *
	 * Abstract class that contains functions and data needed to render a specific kind of drawable.
	 */
	class SceneDefault:
		virtual public neb::fnd::environ::single<neb::fnd::camera::view::Base>,
		virtual public neb::fnd::environ::Three
	{
		public:
			typedef std::weak_ptr<neb::fnd::camera::view::Ridealong>	view_ridealong_weak;
			virtual void					init(parent_t * const & p);
			virtual void					release();
			virtual view_ridealong_weak			create_view_ridealong(
					std::weak_ptr<neb::fnd::core::actor::base> actor);
	};
}}}

#endif
