//-----------------------------------------------------------------------------
//	Quiver Physics Interface
//
//	Currently just a dummy implementation, maps will not load
//-----------------------------------------------------------------------------
#include "vphysics_interface.h"

class CQuiverPhysics : public IPhysics 
{
public:
//	AppSystem interface
	virtual bool Connect( CreateInterfaceFn factory ) { return true; }
	virtual void Disconnect() {}
	virtual void *QueryInterface( const char *pInterfaceName ) { return Sys_GetFactoryThis()(pInterfaceName, nullptr); }
	virtual InitReturnVal_t Init() { return INIT_OK; }
	virtual void Shutdown() {}

//	IPhysics interface
	virtual IPhysicsEnvironment *CreateEnvironment( void ) { return NULL; }
	virtual void DestroyEnvironment( IPhysicsEnvironment * ) {}
	virtual IPhysicsEnvironment		*GetActiveEnvironmentByIndex( int index ) { return NULL; }
	virtual IPhysicsObjectPairHash		*CreateObjectPairHash() { return NULL; }
	virtual void						DestroyObjectPairHash( IPhysicsObjectPairHash *pHash ) {}
	virtual IPhysicsCollisionSet		*FindOrCreateCollisionSet( unsigned int id, int maxElementCount ) { return NULL; }
	virtual IPhysicsCollisionSet		*FindCollisionSet( unsigned int id ) { return NULL; }
	virtual void						DestroyAllCollisionSets() {}
};

class CQuiverPhysicsCollision : public IPhysicsCollision
{
public:
	virtual ~CQuiverPhysicsCollision() {};
	virtual CPhysConvex		*ConvexFromVerts( Vector **pVerts, int vertCount ) { return NULL; }
	virtual CPhysConvex		*ConvexFromPlanes( float *pPlanes, int planeCount, float mergeDistance ) { return NULL; }
	virtual float			ConvexVolume( CPhysConvex *pConvex ) { return NULL; }
	virtual float			ConvexSurfaceArea( CPhysConvex *pConvex ) { return NULL; }
	virtual void			SetConvexGameData( CPhysConvex *pConvex, unsigned int gameData ) {}
	virtual void			ConvexFree( CPhysConvex *pConvex ) {}
	virtual CPhysConvex		*BBoxToConvex( const Vector &mins, const Vector &maxs ) { return NULL; }
	virtual CPhysConvex		*ConvexFromConvexPolyhedron( const CPolyhedron &ConvexPolyhedron ) { return NULL; }
	virtual void			ConvexesFromConvexPolygon( const Vector &vPolyNormal, const Vector *pPoints, int iPointCount, CPhysConvex **pOutput ) {}
	virtual CPhysPolysoup	*PolysoupCreate( void ) { return NULL; }
	virtual void			PolysoupDestroy( CPhysPolysoup *pSoup ) {}
	virtual void			PolysoupAddTriangle( CPhysPolysoup *pSoup, const Vector &a, const Vector &b, const Vector &c, int materialIndex7bits ) {}
	virtual CPhysCollide *ConvertPolysoupToCollide( CPhysPolysoup *pSoup, bool useMOPP ) { return NULL; }
	virtual CPhysCollide	*ConvertConvexToCollide( CPhysConvex **pConvex, int convexCount ) { return NULL; }
	virtual CPhysCollide	*ConvertConvexToCollideParams( CPhysConvex **pConvex, int convexCount, const convertconvexparams_t &convertParams ) { return NULL; }
	virtual void			DestroyCollide( CPhysCollide *pCollide ) {};
	virtual int				CollideSize( CPhysCollide *pCollide ) { return NULL; }
	virtual int				CollideWrite( char *pDest, CPhysCollide *pCollide, bool bSwap = false ) { return NULL; }
	virtual CPhysCollide	*UnserializeCollide( char *pBuffer, int size, int index ) { return NULL; }
	virtual float			CollideVolume( CPhysCollide *pCollide ) { return NULL; }
	virtual float			CollideSurfaceArea( CPhysCollide *pCollide ) { return NULL; }
	virtual Vector			CollideGetExtent( const CPhysCollide *pCollide, const Vector &collideOrigin, const QAngle &collideAngles, const Vector &direction ) { return Vector(0, 0, 0); }
	virtual void			CollideGetAABB( Vector *pMins, Vector *pMaxs, const CPhysCollide *pCollide, const Vector &collideOrigin, const QAngle &collideAngles ) {}
	virtual void			CollideGetMassCenter( CPhysCollide *pCollide, Vector *pOutMassCenter ) {}
	virtual void			CollideSetMassCenter( CPhysCollide *pCollide, const Vector &massCenter ) {}
	virtual Vector			CollideGetOrthographicAreas( const CPhysCollide *pCollide ) { return Vector(0, 0, 0); }
	virtual void			CollideSetOrthographicAreas( CPhysCollide *pCollide, const Vector &areas ) {}
	virtual int				CollideIndex( const CPhysCollide *pCollide ) { return NULL; }
	virtual CPhysCollide	*BBoxToCollide( const Vector &mins, const Vector &maxs ) { return NULL; }
	virtual int				GetConvexesUsedInCollideable( const CPhysCollide *pCollideable, CPhysConvex **pOutputArray, int iOutputArrayLimit ) { return NULL; }
	virtual void TraceBox( const Vector &start, const Vector &end, const Vector &mins, const Vector &maxs, const CPhysCollide *pCollide, const Vector &collideOrigin, const QAngle &collideAngles, trace_t *ptr ) {}
	virtual void TraceBox( const Ray_t &ray, const CPhysCollide *pCollide, const Vector &collideOrigin, const QAngle &collideAngles, trace_t *ptr ) {}
	virtual void TraceBox( const Ray_t &ray, unsigned int contentsMask, IConvexInfo *pConvexInfo, const CPhysCollide *pCollide, const Vector &collideOrigin, const QAngle &collideAngles, trace_t *ptr ) {}
	virtual void TraceCollide( const Vector &start, const Vector &end, const CPhysCollide *pSweepCollide, const QAngle &sweepAngles, const CPhysCollide *pCollide, const Vector &collideOrigin, const QAngle &collideAngles, trace_t *ptr ) {}
	virtual bool			IsBoxIntersectingCone( const Vector &boxAbsMins, const Vector &boxAbsMaxs, const truncatedcone_t &cone ) { return NULL; }
	virtual void			VCollideLoad( vcollide_t *pOutput, int solidCount, const char *pBuffer, int size, bool swap = false ) {}
	virtual void			VCollideUnload( vcollide_t *pVCollide ) {}
	virtual IVPhysicsKeyParser	*VPhysicsKeyParserCreate( const char *pKeyData ) { return NULL; }
	virtual void			VPhysicsKeyParserDestroy( IVPhysicsKeyParser *pParser ) {}
	virtual int				CreateDebugMesh( CPhysCollide const *pCollisionModel, Vector **outVerts ) { return NULL; }
	virtual void			DestroyDebugMesh( int vertCount, Vector *outVerts ) {}
	virtual ICollisionQuery *CreateQueryModel( CPhysCollide *pCollide ) { return NULL; }
	virtual void			DestroyQueryModel( ICollisionQuery *pQuery ) {}
	virtual IPhysicsCollision *ThreadContextCreate( void ) { return NULL; }
	virtual void			ThreadContextDestroy( IPhysicsCollision *pThreadContex ) {}
	virtual CPhysCollide	*CreateVirtualMesh( const virtualmeshparams_t &params ) { return NULL; }
	virtual bool			SupportsVirtualMesh() { return NULL; }
	virtual bool			GetBBoxCacheSize( int *pCachedSize, int *pCachedCount ) { return NULL; }
	virtual CPolyhedron		*PolyhedronFromConvex( CPhysConvex * const pConvex, bool bUseTempPolyhedron ) { return NULL; }
	virtual void			OutputDebugInfo( const CPhysCollide *pCollide ) {}
	virtual unsigned int	ReadStat( int statID ) { return NULL; }
};

class CQuiverPhysicsSurfaceProps : public IPhysicsSurfaceProps
{
public:
	virtual ~CQuiverPhysicsSurfaceProps( void ) {}

	virtual int		ParseSurfaceData( const char *pFilename, const char *pTextfile ) { return NULL; }
	virtual int		SurfacePropCount( void ) const { return NULL; }
	virtual int		GetSurfaceIndex( const char *pSurfacePropName ) const { return NULL; }
	virtual void	GetPhysicsProperties( int surfaceDataIndex, float *density, float *thickness, float *friction, float *elasticity ) const {};
	virtual surfacedata_t	*GetSurfaceData( int surfaceDataIndex ) { return NULL; }
	virtual const char		*GetString( unsigned short stringTableIndex ) const { return ""; }
	virtual const char		*GetPropName( int surfaceDataIndex ) const{ return ""; }
	virtual void	SetWorldMaterialIndexTable( int *pMapArray, int mapSize ) {};
	virtual void	GetPhysicsParameters( int surfaceDataIndex, surfacephysicsparams_t *pParamsOut ) const {};
};