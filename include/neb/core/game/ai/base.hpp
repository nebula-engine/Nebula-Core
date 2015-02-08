#ifndef PHYSX_GAME_AI_BASE_HPP
#define PHYSX_GAME_AI_BASE_HPP

#include <gal/etc/timestep.hpp>

#include <neb/core/itf/shared.hpp>

#include <neb/core/core/actor/util/decl.hpp>

namespace neb { namespace fnd { namespace game { namespace ai {

	class base:
		virtual public neb::fnd::itf::shared
	{
		public:

			void							step(gal::etc::timestep const & ts);
		public:
			std::weak_ptr<neb::fnd::core::actor::base>		actor_;
			/** @brief target
			 */
			std::weak_ptr<neb::fnd::core::actor::base>		target_;

	};


}}}}

#endif

