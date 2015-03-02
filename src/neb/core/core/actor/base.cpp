
#include <gal/log/log.hpp>

#include <neb/fnd/util/config.hpp>
#include <neb/fnd/util/debug.hpp>
#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/core/actor/Base.hpp>
#include <neb/fnd/core/actor/util/decl.hpp>
#include <neb/fnd/core/scene/Base.hpp>
#include <neb/fnd/game/weapon/SimpleProjectile.hpp>

typedef neb::fnd::core::actor::base THIS;

neb::fnd::core::actor::base::base():
	density_(2.0),
	health_(1.0)
{
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);
}
/*neb::fnd::core::actor::base::base(std::shared_ptr<neb::fnd::core::actor::util::parent> parent):
  gal::stl::child<parent_t>(parent.get()),
  density_(10.0)
  {
  LOG(lg, neb::fnd::core::actor::sl, debug) << __FUNCSIG__;
  assert(parent);
  }*/
neb::fnd::core::actor::base::~base()
{
	printv_func(DEBUG);

	assert(neb::fnd::core::actor::util::parent::map_.empty());
	assert(neb::fnd::core::shape::util::parent::map_.empty());

}
void		neb::fnd::core::actor::base::init(parent_t * const & p)
{
	printv_func(DEBUG);
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);

	neb::fnd::core::actor::util::parent::initChildren(this);
	neb::fnd::core::shape::util::parent::initChildren(this);
}
void		neb::fnd::core::actor::base::release() {
	printv_func(DEBUG);
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);

	gal::itf::__release::release();

	neb::fnd::core::actor::util::parent::clear();
	neb::fnd::core::shape::util::parent::clear();
	neb::fnd::game::weapon::util::parent::clear();
}
/*std::shared_ptr<neb::fnd::core::actor::util::parent>	neb::fnd::core::actor::base::get_parent() {
  auto parent(parent_.lock());
  assert(parent);
  return parent;
  }*/
bool							neb::fnd::core::actor::base::hasScene() const
{
	printv_func(DEBUG);
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);

	if(!hasParent()) return false;

	auto scene = dynamic_cast<neb::fnd::core::scene::base*>(getParent());

	if(scene) return true;

	auto actor = dynamic_cast<neb::fnd::core::actor::base*>(getParent());

	assert(actor);

	return actor->hasScene();
}
neb::fnd::core::scene::base*				neb::fnd::core::actor::base::getScene() const
{
	printv_func(DEBUG);
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);

	assert(hasParent());

	auto scene = dynamic_cast<neb::fnd::core::scene::base*>(getParent());

	if(scene) return scene;

	auto actor = dynamic_cast<neb::fnd::core::actor::base*>(getParent());

	assert(actor);

	assert(actor != this);

	return actor->getScene();
}
gal::math::pose				neb::fnd::core::actor::base::getPose() const
{
	return pose_;
}
gal::math::pose				neb::fnd::core::actor::base::getPoseGlobal() const
{
	printv_func(DEBUG);
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);

	auto p = getParent()->getPoseGlobal() * getPose();

	return p;
}
void			neb::fnd::core::actor::base::v_set_pose_data(
		gal::math::pose const & pose)
{
	__set_pose_data(pose);
}
void			neb::fnd::core::actor::base::__set_pose_data(
		gal::math::pose const & pose)
{
	pose_ = pose;

	neb::fnd::core::shape::util::parent::callbackPose(pose);

	flag_.set(neb::fnd::core::actor::util::flag::E::SHOULD_UPDATE);
}
void		neb::fnd::core::actor::base::step(gal::etc::timestep const & ts)
{
	printv_func(DEBUG);
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);
	
	//typedef neb::fnd::core::actor::util::parent A;

	actors::step(ts);
	shapes::step(ts);

	//A::map_.for_each([&] (A::map_type::iterator it) {
	//		it->ptr_->step(ts);
	//		});

	//S::map_.for_each([&] (S::map_type::iterator it) {
	//		it->ptr_->step(ts);
	//		});

}
std::weak_ptr<neb::fnd::core::shape::base>		neb::fnd::core::actor::base::createShapeCube(
		gal::math::pose const & pose,
		double size)
{
	printv_func(DEBUG);

	neb::fnd::core::shape::cuboid::Desc desc(
			pose,
			glm::vec3(size)
			);

	auto shape = createShapeCuboid(desc);

	return shape;

}

std::weak_ptr<neb::fnd::core::shape::base>		neb::fnd::core::actor::base::createShapeLightSpot(
		gal::math::pose const & pose,
		glm::vec3 direction)
{
	printv_func(DEBUG);

	auto shape = createShapeBase(pose).lock();

	shape->createLightSpot(direction);

	return shape;
}
void			THIS::load(
		ba::polymorphic_iarchive & ar, unsigned int const & v)
{
	//BOOST_SERIALIZATION_BASE_OBJECT_NVP(gal::itf::shared);
	//BOOST_SERIALIZATION_BASE_OBJECT_NVP(neb::fnd::core::actor::base);

	__serialize(ar, v);
}
void			THIS::save(
		ba::polymorphic_oarchive & ar, unsigned int const & v) const
{
	//BOOST_SERIALIZATION_BASE_OBJECT_NVP(gal::itf::shared);
	//BOOST_SERIALIZATION_BASE_OBJECT_NVP(neb::fnd::core::actor::base);

	const_cast<THIS*>(this)->__serialize(ar, v);
}
typedef neb::fnd::game::weapon::SimpleProjectile Weapon;
std::weak_ptr<Weapon>	THIS::createWeaponSimpleProjectile(
		std::shared_ptr<neb::fnd::input::source> src,
		double size,
		double damage,
		double velocity)
{
	printv_func(DEBUG);
	//auto self(isPxActorBase());
	
	std::shared_ptr<Weapon> weap(new Weapon());

	//weap->actor_ = self;
	weap->setParent(this);

	weap->connect(src);

	weap->velocity_ = velocity;
	weap->size_ = size;
	weap->damage_ = damage;

	neb::fnd::game::weapon::util::parent::insert(weap);

	return weap;
}


void			THIS::hit()
{
	printv_func(DEBUG);

	auto parent(getParent());

	unsigned int w2 = simulation_.word2;

	if(w2 & phx::filter::filter::PROJECTILE)
	{
		printv(DEBUG, "%p is projectile, erase\n", shared_from_this().get());
		parent->erase(_M_index);
	}

	if(flag_.any(neb::fnd::core::actor::util::flag::E::DESTRUCTIBLE)) {
		damage(0.6f);
	}
}
void			THIS::damage(double h)
{
	printv_func(DEBUG);

	health_ -= h;
	if(health_ < 0) {
		getParent()->erase(_M_index);
	}
}








