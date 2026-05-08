#pragma once

class SceneBase
{
public:
    SceneBase() {
    
        if (GetAsyncKeyState(VK_RETURN) & 0x8000)
        {
            keyFlg = true;
        }
        else
        {
            keyFlg = false;
        }
    
    }
   ~SceneBase() {} // 仮想デストラクタ（必須）

    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void Release() = 0;
    virtual void ImGuiUpdate() {}
protected:
   bool keyFlg = false;
};