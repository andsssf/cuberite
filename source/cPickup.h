
#pragma once

#include "cEntity.h"




class cPacket_PickupSpawn;
class cPlayer;
class cItem;





// tolua_begin
class cPickup :
	public cEntity
{
	// tolua_end
	typedef cEntity super;
	// tolua_begin
	
public:
	// tolua_end
	CLASS_PROTOTYPE();

	cPickup(int a_X, int a_Y, int a_Z, const cItem & a_Item, float a_SpeedX = 0.f, float a_SpeedY = 0.f, float a_SpeedZ = 0.f);	//tolua_export
	~cPickup();														//tolua_export
	
	virtual void Initialize(cWorld * a_World) override;

	cItem *       GetItem(void)       {return m_Item; }								//tolua_export
	const cItem * GetItem(void) const {return m_Item; }

	virtual void SpawnOn(cClientHandle & a_ClientHandle) override;
	
	virtual bool CollectedBy( cPlayer* a_Dest );					//tolua_export

	void Tick(float a_Dt);
	void HandlePhysics(float a_Dt);
	
	const Vector3f & GetSpeed(void) const {return m_Speed; }
	
private:

	Vector3f   m_Speed;
	Vector3f   m_ResultingSpeed;	 //Can be used to modify the resulting speed for the current tick ;)

	Vector3f   m_WaterSpeed;
	bool       m_bOnGround;
	bool       m_bReplicated;

	float m_Timer;

	cItem* m_Item;

	bool m_bCollected;
};  //tolua_export




