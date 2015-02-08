#ifndef NEB_CORE_CONTEXT_FBOM_HPP
#define NEB_CORE_CONTEXT_FBOM_HPP

#include <neb/core/itf/shared.hpp>
#include <neb/core/context/Base.hpp>
#include <neb/core/environ/util/decl.hpp>

namespace neb { namespace fnd { namespace context {
	class FBOM:
		virtual public neb::fnd::context::Base
	{
		public:
			typedef neb::fnd::environ::shadow::Point ESP;
			typedef neb::fnd::environ::shadow::Directional ESD;

			virtual std::weak_ptr<ESP>		createEnvironShadowPoint() = 0;
			virtual std::weak_ptr<ESD>		createEnvironShadowDirectional() = 0;

			virtual void				setTexture(std::shared_ptr<neb::fnd::itf::shared> texture) = 0;
	};
}}}

#endif
