#ifndef NEB_FND_PLUG_GFX_WINDOW_BASE_HPP
#define NEB_FND_PLUG_GFX_WINDOW_BASE_HPP

#include <neb/fnd/window/Base.hpp>

namespace neb { namespace fnd { namespace plug { namespace gfx { namespace window {
	class Base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::tmp::Child<neb::fnd::window::Base>
	{
		public:
			typedef neb::fnd::window::Base FND;
			virtual void		init(parent_t * const & p) = 0;
			//virtual void		render() = 0;
			//virtual void		setTexture(
			//		std::shared_ptr<neb::fnd::itf::shared> tex) = 0;
	};
}}}}}


#endif
