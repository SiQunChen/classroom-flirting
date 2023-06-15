#pragma once

#include "Role.h"

class Normalgirl1 : public Girl
{
public:
	Normalgirl1() = default;
	~Normalgirl1() {}
	void Load() override;
};

class Normalgirl2 : public Girl
{
public:
	Normalgirl2() = default;
	~Normalgirl2() {}
	void Load() override;
};