#include <neb/core/context/Base.hpp>

#include <neb/core/environ/util/Parent.hpp>

typedef neb::fnd::environ::util::Parent THIS;

neb::fnd::app::Base* const			THIS::get_fnd_app()
{
	auto context = is_fnd_context_Base();

	return context->get_fnd_app();
}


