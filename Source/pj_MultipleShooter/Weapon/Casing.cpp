// Fill out your copyright notice in the Description page of Project Settings.


#include "Casing.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
ACasing::ACasing()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CasingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CasingMesh"));
	SetRootComponent(CasingMesh);
	CasingMesh->SetCollisionResponseToChannel(ECC_Camera,ECR_Ignore);
	CasingMesh->SetSimulatePhysics(true);
	CasingMesh->SetEnableGravity(true);
	CasingMesh->SetNotifyRigidBodyCollision(true);
	ShellEjectionImpluse = 1000.f;
}

// Called when the game starts or when spawned
void ACasing::BeginPlay()
{
	Super::BeginPlay();
	CasingMesh->OnComponentHit.AddDynamic(this, &ACasing::OnHit);
	CasingMesh->AddImpulse(GetActorForwardVector());
	
}

void ACasing::OnHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, FVector NormalImpulse,
	const FHitResult& Hit)
{
	if (ShellSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, ShellSound, GetActorLocation());
	}
	
	GetWorldTimerManager().SetTimer(DestroyTimerHandler, [this] {Destroy(); }, 2.f,false);
}

// Called every frame
void ACasing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

