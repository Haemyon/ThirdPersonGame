// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

//체력이 변하면 사용되는 델리게이트 정의입니다.
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangedHP, class UStatusComponent*, statComp);
//스테미나가 변하면 사용되는 델리게이트 정의입니다.
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangedSP, class UStatusComponent*, statComp);

UENUM(BlueprintType)
enum class EActionState : uint8
{
	NORMAL,
	RUN,
	ROLL,
	ATTACK,
	JUMP
};

UCLASS()
class THIRDPERSONGAME_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	//캐릭터의 체력이 변하면 실행되는 델리게이트 입니다.
	UPROPERTY(BlueprintAssignable)
		FOnChangedHP OnChangedHP;
	//캐릭터의 스테미나가 변하면 실행되는 델리게이트 입니다.
	UPROPERTY(BlueprintAssignable)
		FOnChangedSP OnChangedSP;

protected:
	//델리게이트에 저장되는 함수들 입니다.
	UFUNCTION()
		virtual void OnChangedHPEvent(class UStatusComponent* StatComp) {}
	UFUNCTION()
		virtual void OnChangedSPEvent(class UStatusComponent* StatComp) {}

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UStatusComponent* StatusComponent;

	UPROPERTY(BlueprintReadOnly)
		EActionState ActionState;

	virtual void SetActionState(EActionState newState) {}

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	EActionState GetActionState() { return ActionState; }

	UStatusComponent* GetStatusComponent() { return StatusComponent; }
	/// <summary>
	/// 
	/// </summary>
	/// <param name="DamageAmount">피해량</param>
	/// <param name="DamageEvent">피해에 대한 필요한 정보를 저장하는 구조체</param>
	/// <param name="EventInstingator">이 대상에게 피해를 준 컨트롤러</param>
	/// <param name="DamageCauser">이 대상에게 피해를 준 물체</param>
	/// <returns>최종 대미지</returns>
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
};