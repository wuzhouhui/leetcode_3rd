int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
	int top = D < H ? D : H;
	int down = B > F ? B : F;
	int left = A > E ? A : E;
	int right = C < G ? C : G;
	if (top <= down || left >= right)
		return((D - B) * (C - A) + (H - F) * (G - E));
	else
		return((D - B) * (C - A) - (top - down) * (right - left)
				+ (H - F) * (G - E));
}

main(){}
