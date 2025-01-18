def street_lights_state(lights, M):
    n = len(lights)
    
    for day in range(M):
        # Modify lights in-place, but keep a temporary list to store updates
        for i in range(n):
            # Determine adjacent light values (with 0 for boundaries)
            left = lights[i - 1] if i > 0 else 0
            right = lights[i + 1] if i < n - 1 else 0
            
            # Update the current light based on adjacent values
            if left == right:
                lights[i] = 0
            else:
                lights[i] = 1
                
    return lights

# Example usage
initial_state = [1,1,1,0,1,1,1,1]  # Example initial state of lights
M = 2  # Number of days to simulate

result = street_lights_state(initial_state, M)
print("State after", M, "days:", result)
