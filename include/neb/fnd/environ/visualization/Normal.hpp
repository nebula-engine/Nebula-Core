#ifndef NEBULA_CORE_ENVIRON_NORMAL_MAP_HPP
#define NEBULA_CORE_ENVIRON_NORMAL_MAP_HPP

#include <neb/fnd/environ/Single.hpp>

namespace neb { namespace fnd { namespace environ { namespace visualization {
	/** @brief Normal
	 */
	class Normal:
		virtual public neb::fnd::environ::single<neb::fnd::camera::view::Base>
	{
		public:
/*			typedef std::shared_ptr<neb::gfx::glsl::program::Base>		program_shared;
			typedef std::shared_ptr<neb::gfx::camera::view::Base>		view_shared;
			typedef std::shared_ptr<neb::gfx::camera::proj::Base>		proj_shared;*/
		public:
			//virtual void		init();
			//virtual void		step(gal::etc::timestep const & ts);
	};
}}}}

#endif
