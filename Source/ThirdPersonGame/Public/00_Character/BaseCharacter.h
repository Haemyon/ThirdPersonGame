// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

//ü���� ���ϸ� ���Ǵ� ��������Ʈ �����Դϴ�.
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangedHP, class UStatusComponent*, statComp);
//���׹̳��� ���ϸ� ���Ǵ� ��������Ʈ �����Դϴ�.
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangedSP, class UStatusComponent*, statComp);

UENUM(BlueprintType)
enum class EActionState : uint8
{
	NORMAL,
	RUN,
	ROLL,
	ATTACK
};

UCLASS()
class THIRDPERSONGAME_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	//ĳ������ ü���� ���ϸ� ����Ǵ� ��������Ʈ �Դϴ�.
	UPROPERTY(BlueprintAssignable)
		FOnChangedHP OnChangedHP;
	//ĳ������ ���׹̳��� ���ϸ� ����Ǵ� ��������Ʈ �Դϴ�.
	UPROPERTY(BlueprintAssignable)
		FOnChangedSP OnChangedSP;

protected:
	//��������Ʈ�� ����Ǵ� �Լ��� �Դϴ�.
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
};