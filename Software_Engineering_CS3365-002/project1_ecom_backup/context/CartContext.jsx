import React, { createContext, useContext, useReducer } from 'react';

const CartContext = createContext();

const initialState = {
  cartItems: []
};

function cartReducer(state, action) {
  switch (action.type) {
    case 'ADD_TO_CART':
      const existing = state.cartItems.find(item => item.id === action.payload.id);
      if (existing) {
        return {
          ...state,
          cartItems: state.cartItems.map(item =>
            item.id === action.payload.id ? { ...item, quantity: item.quantity + 1 } : item
          )
        };
      } else {
        return {
          ...state,
          cartItems: [...state.cartItems, { ...action.payload, quantity: 1 }]
        };
      }
    case 'REMOVE_FROM_CART':
      return {
        ...state,
        cartItems: state.cartItems.filter(item => item.id !== action.payload)
      };
    default:
      return state;
  }
}

export function CartProvider({ children }) {
  const [state, dispatch] = useReducer(cartReducer, initialState);
  return (
    <CartContext.Provider value={{ cartItems: state.cartItems, dispatch }}>
      {children}
    </CartContext.Provider>
  );
}

export function useCart() {
  return useContext(CartContext);
}